# [DEV3] Laboratoires
Mes solutions des TD's de l'UE DEV3 à l'École Supérieur d'Informatique de Bruxelles
## Structure des fichiers
```
.
├── i1
│   ├── src
│   │   └── main.c
│   └── CMakeLists.txt
├── td01
│   ├── src
│   │   ├── main.c
│   │   ├── mathesi.c
│   │   └── mathesi.h
│   ├── CMakeLists.txt
│   └── doxygen
├── td02
│   ├── src
│   │   ├── main.c
│   │   ├── tableaux.c
│   │   └── tableaux.h
│   └── CMakeLists.txt
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

### Executer le main d'un TD
Après avoir compilé:
```bash
$ ./td01/build/td01
```
```bash
$ ./td02/build/td02
```
```bash
$ ./td03/build/td03
```
```bash
$ ./td04/build/td04
```

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
