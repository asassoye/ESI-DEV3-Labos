# [DEV3] Laboratoires
Mes solutions des TD's de l'UE DEV3 à l'École Supérieur d'Informatique de Bruxelles
## Structure des fichiers
```
.
├── common
│   ├── src
│   │   ├── mathesi.c
│   │   ├── mathesi.cpp
│   │   ├── mathesi.h
│   │   ├── mathesi.hpp
│   │   ├── utilscpp.cpp
│   │   └── utilscpp.hpp
│   └── CMakeLists.txt
├── i1
│   ├── src
│   │   ├── main.c
│   │   ├── primestat.c
│   │   ├── primestat.h
│   │   ├── statsample.c
│   │   └── statsample.h
│   ├── CMakeLists.txt
│   └── interro.pdf
├── td01
│   ├── src
│   │   └── main.c
│   ├── CMakeLists.txt
│   ├── doxygen
│   └── td01_c.pdf
├── td02
│   ├── src
│   │   ├── main.c
│   │   ├── tableaux.c
│   │   └── tableaux.h
│   ├── CMakeLists.txt
│   └── td02_c.pdf
├── td03
│   ├── src
│   │   ├── main.c
│   │   ├── str.c
│   │   └── str.h
│   ├── CMakeLists.txt
│   └── td03_c.pdf
├── td04
│   ├── src
│   │   ├── main.c
│   │   ├── PrimeFactor.c
│   │   ├── PrimeFactor.h
│   │   ├── PrimeFactorization.c
│   │   ├── PrimeFactorization.h
│   │   ├── td04.c
│   │   └── td04.h
│   ├── CMakeLists.txt
│   └── td04_c.pdf
├── td05
│   ├── src
│   │   ├── main.c
│   │   ├── slcircularlist.c
│   │   ├── slcircularlist.h
│   │   ├── slcircularlist_utility.c
│   │   ├── slcircularlist_utility.h
│   │   ├── slnode.c
│   │   ├── slnode.h
│   │   ├── slnode_utility.c
│   │   ├── slnode_utility.h
│   │   └── value_t.h
│   ├── CMakeLists.txt
│   ├── td05_c.pdf
│   └── td05_c_withAppendix.pdf
├── td06
│   ├── src
│   │   └── main.cpp
│   ├── CMakeLists.txt
│   └── td06_cpp.pdf
├── td07
│   ├── src
│   │   ├── main.cpp
│   │   ├── td07.cpp
│   │   └── td07.hpp
│   ├── CMakeLists.txt
│   └── td07_cpp.pdf
├── CMakeLists.txt
├── LICENSE
├── Makefile
└── README.md
```

## Build

Pour compiler executez la commande suivante

```bash
$ make
```

Pour compiler en debug:

```bash
$ make debug
```

### Executer un TD

Après avoir compilé:

```bash
$ ./{td}/build/{env}/{td}
```

avec:

- env ∈ {`Release`,`Debug`}:
- td ∈ {`td01`, `td02`,`td03`,`td04`,`td01`,`td05`,`td06`,`td07`}

### Executer le main d'une interrogation

Après avoir compilé:

```bash
$ ./i1/build/interro1
```

Si vous n'arrivez pas a compiler l'interrogation avec la commande `make` voici une alternative

```bash
$ make interro1
```

### Clean les builds
```bash
$ make clean
```
