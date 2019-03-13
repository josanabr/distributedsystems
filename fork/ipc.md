---
# IPC - Inter Process Communication 

* Fork

---

# Fork

* System call used to create a new process
* `fork()` invoked from a running process creates a new process (child process) which is identical to his parent process
* A parent process should always `wait()` for its children's `exit()`

---

# Fork

* A sudden death of a child process causes to remain in  `defunct` state
* `defunct` processes are usually killed by `init` process
* Let's see an [example](https://raw.githubusercontent.com/josanabr/distributedsystems/master/fork/01-fork.c)

---

# Comments about first example

* 
* `WEXITSTATUS()` is a macro defined in `<sys/waith.h>`

---

# Let us check more `fork()` examples

[More examples](https://github.com/josanabr/distributedsystems/tree/master/fork)

---

# A minimal tiny web server


