#! /usr/bin/python3

import argparse
import os
import subprocess
from typing import Generator, List, Tuple


class AnsiCode:
    RED = '\033[91m'
    GREEN = '\033[92m'
    RESET = '\u001b[0m'
    BOLD = '\u001b[1m'


def print_ansi(str: str, *codes):
    if codes:
        for code in codes:
            print(code, end='')

    print(str)

    if codes:
        print(AnsiCode.RESET, end='')


def collect_samples(
        include_valid: bool,
        include_error: bool,
        include_precompiled: bool,
        include_check_list: bool,
        include_64: bool,
        include_32: bool
    ) -> Generator[Tuple[str, List[List[str]]], None, None]:
    if include_valid:
        if include_64:
            yield 'basic', [['main64.o'], ['exe64'], ['main64.o', 'exe64']]
            yield 'default_file', [[]]
            yield 'multi_arch', [['exe']]
            yield 'static_functions', [['main64.o'], ['exe64']]
            yield 'global_variables', [['main64.o'], ['exe64']]
            yield 'inline_global_variable', [['main64.o'], ['exe64']]
            yield 'shared_lib', [['foo64.o'], ['bar64.o'], ['libtest64.so'], ['main64.o'], ['exe64']]

        if include_32:
            yield 'basic', [[], ['main32.o'], ['exe32'], ['main32.o', 'exe32']]
            yield 'static_functions', [['main32.o'], ['exe32']]
            yield 'global_variables', [['main32.o'], ['exe32']]
            yield 'inline_global_variable', [['main32.o'], ['exe32']]
            yield 'shared_lib', [['foo32.o'], ['bar32.o'], ['libtest32.so'], ['main32.o'], ['exe32']]

    if include_error:
        yield 'basic', [['non_existent_file']]
        yield 'not_elf', [['exe']]

        if include_64:
            yield 'stripped_elf', [['exe64']]

        if include_32:
            yield 'stripped_elf', [['exe32']]

    if include_precompiled:
        if include_64:
            yield 'precompiled', [
                ['bin1_x64'],
                ['bin2_x64'],
                ['bin3_x64'],
                ['bin4_x64'],
                ['lib1_shname_corrupted_x64.so'],
                ['lib1_shoffset2_corrupted_x64.so'],
                ['lib1_shoffset_corrupted_x64.so'],
                ['lib1_x64.so'],
                ['obj1_identabi_corrupted_x64.o'],
                ['obj1_identclass2_corrupted_x64.o'],
                ['obj1_identclass_corrupted_x64.o'],
                ['obj1_identdata_corrupted_x64.o'],
                ['obj1_identelf2_corrupted_x64.o'],
                ['obj1_identelf_corrupted_x64.o'],
                ['obj1_identosabi_corrupted_x64.o'],
                ['obj1_identpad_corrupted_x64.o'],
                ['obj1_identversion_corrupted_x64.o'],
                ['obj1_x64.o'],
                ['obj2_eshoff2_corrupted_x64.o'],
                ['obj2_eshoff3_corrupted_x64.o'],
                ['obj2_eshoff_corrupted_x64.o'],
                ['obj2_x64.o'],
                ['obj3_ehsize_corrupted_x64.o'],
                ['obj3_shentsize_corrupted_x64.o'],
                ['obj3_shnum2_corrupted_x64.o'],
                ['obj3_shnum_corrupted_x64.o'],
                ['obj3_x64.o'],
                ['obj4_x64.o']
            ]

        if include_32:
            yield 'precompiled', [
                ['bin2_x32'],
                ['lib1_x32.so'],
                ['obj1_x32.o'],
                ['obj2_x32.o'],
                ['obj3_x32.o'],
                ['obj4_x32.o']
            ]

    if include_check_list:
        yield 'check_list', [
            ['error_header'],
            ['header'],
            ['header_and_prog'],
            ['header_and_prog_copy'],
            ['header_copy'],
            ['header_offset_error'],
            ['unterminated_string'],
            ['wrong_arch']
        ]


def test_samples(ft_nm_path: str, samples: List[Tuple[str, List[List[str]]]], rebuild: bool, stop_on_error: bool, flag: str):
    def execute_nm(cmd: List[str], workdir: str) -> Tuple[str, int]:
        if flag:
            cmd.append(f'-{flag}')

        process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=workdir, close_fds=True)
        stdout = process.communicate()[0]
        return_code = process.returncode

        return stdout.decode('utf8'), return_code

    def test_target(workdir: str, args: List[str]) -> bool:
        expected_out, expected_return_code = execute_nm(['nm'] + args, workdir)
        actual_out, actual_return_code = execute_nm([ft_nm_path] + args, workdir)

        # Compare output when exit codes differ or when they are both 0.
        if not (expected_return_code and actual_return_code):
            if expected_out != actual_out or expected_return_code != actual_return_code:
                print_ansi(f'Test failed: workdir="{workdir}", args="{args}"', AnsiCode.RED, AnsiCode.BOLD)
                print_ansi('// EXPECTED ////////////////////////////////////////////////', AnsiCode.RED)
                print_ansi(f'exit code: {expected_return_code}', AnsiCode.RED)
                print_ansi(expected_out, AnsiCode.RED)
                print_ansi('\\' * 60, AnsiCode.RED)
                print_ansi('// ACTUAL //////////////////////////////////////////////////', AnsiCode.RED)
                print_ansi(f'exit code: {actual_return_code}', AnsiCode.RED)
                print_ansi(actual_out, AnsiCode.RED)
                print_ansi('\\' * 60, AnsiCode.RED)
                return False

        print_ansi(f'Test passed: workdir="{workdir}", args="{args}"', AnsiCode.GREEN, AnsiCode.BOLD)
        return True

    for sample_name, args_list in samples:
        subprocess.call(
            ['make', 're'] if rebuild else ['make'],
            cwd=f'samples/{sample_name}',
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL
        )

        for args in args_list:
            result = test_target(f'samples/{sample_name}', args)
            if stop_on_error and not result:
                break


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-a', '--all', help='Run all tests.', action='store_true')
    parser.add_argument('-gv', '--group-valid', help='Run tests on valid samples.', action='store_true')
    parser.add_argument('-ge', '--group-error', help='Run test on error samples.', action='store_true')
    parser.add_argument('-gp', '--group-precompiled', help='Run test on precompiled samples.', action='store_true')
    parser.add_argument('-gc', '--group-checklist', help='Run test on samples from check list.', action='store_true')
    parser.add_argument('-a64', '--arch-64', help='Test x86_64 ELF files.', action='store_true')
    parser.add_argument('-a32', '--arch-32', help='Test x86 ELF files.', action='store_true')
    parser.add_argument('-r', '--reset', help='Invoke "make re" on each sample, instead of "make"', action='store_true')
    parser.add_argument('-s', '--stop', help='Stop on error.', action='store_true')
    parser.add_argument('-f', '--flag', help='Run both programs with specified flag. Needed for bonus', type=str)
    args = vars(parser.parse_args())

    include_valid = args['all'] or args['group_valid']
    include_error = args['all'] or args['group_error']
    include_precompiled = args['all'] or args['group_precompiled']
    include_check_list = args['all'] or args['group_checklist']
    include_64 = args['all'] or args['arch_64']
    include_32 = args['all'] or args['arch_32']
    reset = args['reset']
    stop_on_error = args['stop']
    flag = args['flag']

    samples = list(collect_samples(include_valid, include_error, include_precompiled, include_check_list, include_64, include_32))
    if len(samples) == 0:
        print("No tests to run try. See help: ./test.py --help")

    subprocess.call(
        'make',
        cwd='../main',
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL
    )

    test_samples(os.path.abspath('../main/ft_nm'), samples, reset, stop_on_error, flag)


if __name__ == '__main__':
    main()
