# Demo git for a git introduction

## What is this?

This is a very simple git demo to show its main features and use scenarios. The main two starting scenarios for this demo are starting with a new local repository and starting with
a remote repository. As remote repositories we will be using GitHub. This demo is meant to be given by two persons as to introduce desynchronizations. 

## Creating or initializing a repository

One importan topic in this part involves authorization, this should be discussed at some point. We will use both https and ssh authorization.

### Starting with a local repository

1. Create a new folder for the repository (e.g.: `repo_demo`)
2. Create a README.md file with the following description:

```
# Sorting

## Implementation of a sort function using bubble sort

Implement the following functions:
* void order(int values[], int size)
* int bubbleup(int values[], int size)

The first function should bubbleup values until the array is no longer modified
The second function should travel once through the array, swaping consecutive values when their respective order do not match the expected ordering
```

3. Create a simple .gitignore file with:

```
*.o
*.rar
*.zip
*.tar.gz
```

4. Create the following files: `ordering.h` with the initial code:

```C
#ifndef _ORDERING
#define _ORDERING

void order(int values[], int size);

#endif
```

File `bubblesort.c` with the initial code:

```C
#include <ordering.h>

int minimum(int a, int b);
int maximum(int a, int b);
int bubbleup(int values[], int size);

void order(int values[], int size) {
    //TODO: implement, it should use bubbleup
}

int bubbleup(int values[], int size) {
    //TODO: implement
}

int minimum(int a, int b) {
    //TODO: implement
}

int maximum(int a, int b) {
    //TODO: implement
}
```

File `main.c` with the initial code:

```C
#include <stdlib.h>
#include <stdio.h>
#include <ordering.h>

void main(int argc, char ** argv) {
    int values[argc-1];
    for (int i = 0; i < argc - 1; i++) {
        values[i] = atoi(argv[i+1]);
    }
    printf("[");
    for (int i = 0; i < argc - 1; i++) {
        printf("%d", values[i]);
        if (i + 1 < argc - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
```

5. Initialize a local repository: `git init -b main` (this creates an initial branch called `main`, by default __git__ will use `master` but GitHub uses `main`, and so it's easier starting with this branch name instead).
6. Add the initial files, i.e.: `.gitignore`, `main.c`, `bubblesort.c`, `ordering.h` and `README.md` to the repo:

```Bash
git add *
git commit -m "First commit"

```

7. Create a GitHub repository (without adding any file)
8. Push the local repo into the remote one (here is a good point where to introduce authorization):

```Bash
git remote add origin <URL del repo>
git remote -v
# the previous command allows to verify the remote repository
git push origin main
# only the first time does the push needs to be done in this way
```
9. Show the GitHub repository
10. Presenter should write the following code:

```C
void order(int values[], int size) {
    if (size > 1) {
        int arrayChanged = 0;
        while (!arrayChanged) {
            arrayChanged = bubbleup(values, size);
        }
    }
}
```

11. Helper will now clone the GitHub repository and will write the __bubbleup__ function, and will push it to the repository:

```C
int bubbleup(int values[], int size) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        if (firstValue > secondValue) {
            values[i] = secondValue;
            values[i+1] = firstValue;
            changed = 1;
        }
    }
    return changed;
}
```

12. Presenter will try to push the changes, and will receive a `git pull is required`.
13. Presenter will execute `git pull` and show how everything was automatically merged.
14. Presenter will now modify `ordering.h`, `bubblesort.c`, and `main.c` to define three options to order: __ASCENDING__, __DESCENDING__, and __default__ (ASCENDING); as well as define a variable __size__ in main instead of using `argc-1` everywhere. Modified code is:

For `main.c` is

```C
void main(int argc, char ** argv) {
    int size = argc-1;
    int values[size];
    for (int i = 0; i < size; i++) {
        values[i] = atoi(argv[i+1]);
    }
    orderAscending(values, size);
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", values[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}
```

For `ordering.h` is

```C
typedef enum Ordering {ASCENDING, DESCENDING} Ordering;

void order(int values[], int size, Ordering ordering);
void orderAscending(int values[], int size);
void orderDescending(int values[], int size);
```

For `bubblesort.c` is

```C
int bubbleup(int values[], int size, Ordering ordering);

void order(int values[], int size, Ordering ordering) {
    if (size > 1) {
        int arrayChanged = 0;
        while (!arrayChanged) {
            arrayChanged = bubbleup(values, size, ordering);
        }
    }
}

void orderAscending(int values[], int size) {
    order(values, size, ASCENDING);
}

void orderDescending(int values[], int size){
    order(values, size, DESCENDING);
}

int bubbleup(int values[], int size, Ordering ordering) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        if (ordering == ASCENDING && firstValue > secondValue) {
            values[i] = secondValue;
            values[i+1] = firstValue;
            changed = 1;
        } else if (ordering == DESCENDING && firstValue < secondValue) {
            values[i] = secondValue;
            values[i+1] = firstValue;
            changed = 1;
        }
    }
    return changed;
}
```

15. Helper will rename function `order` to `sort`, and will modify `bubbleup` to use a `minimum` and `maximum` functions; it will implement a `printArray` function, modify the main to use it. The modified code is:

For `main.c`

```C
void printArray(int values[], int size);

void main(int argc, char ** argv) {
    int values[argc-1];
    for (int i = 0; i < argc - 1; i++) {
        values[i] = atoi(argv[i+1]);
    }
    printf("Original array: ");
    printArray(values, argc-1);
    sort(values, argc-1);
    printf("\nSorted array: ");
    printArray(values, argc-1);
    printf("\n");
}

void printArray(int values[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", values[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}
```

For `ordering.h` is

```C
void sort(int values[], int size);
```

For `bubblesort.c` is

```C
int maximum(int a, int b);
int minimum(int a, int b);

void sort(int values[], int size) {
    if (size > 1) {
        int arrayChanged = 0;
        while (!arrayChanged) {
            arrayChanged = bubbleup(values, size);
        }
    }
}

int bubbleup(int values[], int size) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        int maxValue = maximum(firstValue, secondValue);
        int minValue = minimum(firstValue, secondValue);
        values[i] = minValue;
        values[i+1] = maxValue;
        changed = changed || (minValue != firstValue);
    }
    return changed;
}

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int minimum(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}
```


16. Helper will push all changes.
17. Presenter will try to push and should recive a message asking to do a `git pull` first.
18. Presenter will execute `git pull` and, if everything goes as expected, will need to manually solve all conflicts.
19. Presenter will manually solve all conflicts and push again.

_Note: during the demo, it should be nice to use `git status` and `git blame`_

### Using a remote repository

Here we will start by showing GitHub, and a new repository with the same example.

### Authentication

When trying to clone the repository we need to deal with authentication. There are two, most usual, options: the old user and password authentication,
this is achieved by selecting the __HTTPS__ protocol for cloning the repository; and the other method is to use (private, public) key pairs, the public key
is set in your GitHub account, the private key will be stored in your device, using these you will be able to login/authenticate. The second method is
achieved by selecting the __SSH__ protocol for cloning the repository.

### Application token

Since August 13 of 2021, GitHub no longer accepts user and password for the __HTTPS__ protocol. Specifcially it no longer accepts the use of the user's password.
To authenticate for __HTTPS__ protocol, an application access token is required, and this token will be used instead of the password.

### SSH

Using a private/public key pair is really convenient, to use this protocol we first need to generate a new private/public shh key pair. The commands to do this
are the following:

1. `ssh-keygen -t ed25519 -C "your_email@example.com"` to generate a ssh key pair
2. Add the following into file `~/.ssh/config`:
```
Host github.com
  HostName github.com
  IdentityFile <path of private key>
```

_note: you can use the ssh-agent instead of using a config file, but this aproach requires modifying some scripts. If you are insterested you can go to https://docs.github.com/en/authentication/connecting-to-github-with-ssh/working-with-ssh-key-passphrases for information._

After generating the ssh key pair, you need to add the public key into your github account.
