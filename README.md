# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An example of the word which has the length of 45 letters (the maximum word length)

## According to its man page, what does `getrusage` do?

getrusage - get resource usage. It returns resource usage measures for who, which can be one of the following: -RUSAGE_SELF, RUSAGE_CHILDREN, RUSAGE_THREAD

## Per that same man page, how many members are in a variable of type `struct rusage`?

16
struct rusage {
               struct timeval ru_utime; /* user CPU time used */
               struct timeval ru_stime; /* system CPU time used */
               long   ru_maxrss;        /* maximum resident set size */
               long   ru_ixrss;         /* integral shared memory size */
               long   ru_idrss;         /* integral unshared data size */
               long   ru_isrss;         /* integral unshared stack size */
               long   ru_minflt;        /* page reclaims (soft page faults) */
               long   ru_majflt;        /* page faults (hard page faults) */
               long   ru_nswap;         /* swaps */
               long   ru_inblock;       /* block input operations */
               long   ru_oublock;       /* block output operations */
               long   ru_msgsnd;        /* IPC messages sent */
               long   ru_msgrcv;        /* IPC messages received */
               long   ru_nsignals;      /* signals received */
               long   ru_nvcsw;         /* voluntary context switches */
               long   ru_nivcsw;        /* involuntary context switches */
           };

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

In order to avoid copying the values and save both memory and time.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Read every character one-by-one until the end of the file.
    Every character is checked for alphabetical only or apostrophe. In case it's true, then this caracter is added (appended) to the word.
        If a word (from the number of characters) is longer than the maximum length, then it's ignored and a new word is started.
    If the read character in a word is digit, it's also ignored and a new word is started.
    In the other case (if the read character is a space), /0 is added to show the end of the word.
        This word is then check for spelling. If it's misspelled, it's printed out.
        The time for checking is recalculated.
        The number of misspelled words is recalculated.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc()  reads  the next character from stream and returns it as an unsigned char cast to an int, or EOF on end of file or error.
fscanf()  reads  input  from  the stream pointer stream
If we use fscanf() with reading a whole string, we can have an error in case we face with punctuation, which would be considered as a part of a string.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

In order to prevent pointers from changing their position (from the word we are reading and the dictionary we're using respectively)
