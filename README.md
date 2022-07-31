# nm
This is a reimplementation of standard Linux utility 'nm'. This utility lists symbols from a given ELF file.
The goal of the project is to become familiar with ELF format.

## launching VM
```
./vm/scripts/reset.sh
./vm/scripts/launch.sh
```

## build
```
cd main
make
```

## test
```
cd test
./test_suite.py -a
```

## resources
* [Анатомия эльфов. Разбираемся с внутренним устройством ELF-файлов — Хакер](https://xakep.ru/2022/05/11/elf-anatomy/)
* [Symbol Table](https://refspecs.linuxbase.org/elf/gabi4+/ch4.symtab.html)
* [nm man](https://linux.die.net/man/1/nm)
* [Symbol Processing (Linker and Libraries Guide)](https://docs.oracle.com/cd/E19683-01/817-3677/6mj8mbtb8/index.html)
* [GitHub - Jibus22/ft_nm: Implementation of nm()](https://github.com/Jibus22/ft_nm)
