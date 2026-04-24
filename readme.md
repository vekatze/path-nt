# path

`path` is a library to perform path-related operations.

```sh
neut get path https://github.com/vekatze/path-nt/raw/main/archive/0-1-54.tar.zst
```

## Types

### Pure Operations

```neut
// separator-rune == '/'
constant separator-rune: rune

// separator == "/"
constant separator: &string

// is-absolute("/foo") => True
// is-absolute("bar/baz") => False
define is-absolute(path: &string) -> bool

// is-absolute("/foo") => False
// is-absolute("bar/baz") => True
define is-relative(path: &string) -> bool

// clean("foo/./bar//../buz.txt") => "foo/buz.txt"
define clean(path: &string) -> string

// append("test/sample", "foo.txt")      => "test/sample/foo.txt"
// append("test/sample/", "foo.txt")     => "test/sample/foo.txt"
// append("test/sample", "/foo.txt")     => "test/sample/foo.txt"
// append("test/sample/", "/foo.txt")    => "test/sample/foo.txt"
// append("test/.//sample/", "/foo.txt") => "test/sample/foo.txt"
define append(path1: &string, path2: &string) -> string

// take-last("test/sample/foo.txt") => "foo.txt"
// take-last("test/.//sample/foo.txt") => "foo.txt"
// take-last("test/sample/") => ""
define take-last(path: &string) -> string

// drop-last("test/sample/foo.txt") => "test/sample"
// drop-last("test/.//sample/foo.txt") => "test/sample"
// drop-last("test/sample/") => "test/sample"
define drop-last(path: &string) -> string

// split-extension("test/sample/foo.txt")     => Pair("test/sample/foo", ".txt")
// split-extension("test/.//sample/foo.txt")  => Pair("test/sample/foo", ".txt")
// split-extension("test/sample/foo")         => Pair("test/sample/foo", "")
// split-extension("test/sample/.foo")        => Pair("test/sample/.foo", "")
// split-extension("test/sample/.foo.tar.gz") => Pair("test/sample/.foo.tar", ".gz")
define split-extension(path: &string) -> pair(string, string)
```

### IO Operations

```neut
// A type for directory entries.
data dtype {
| DT_BLK
| DT_CHR
| DT_DIR
| DT_FIFO
| DT_LNK
| DT_REG
| DT_SOCK
| DT_UNKNOWN
}

data dirent {
| Dirent(
    kind: dtype,
    name: string,
  )
}

// Returns the absolute path of the current directory.
define get-current-directory() -> system(string)

// Reads the content of the given directory.
define read-directory(p: &string) -> system(list(dirent))

// Reads the content of the given directory and returns paths joined to `dir-path`.
define get-directory-contents(dir-path: &string) -> system(list(string))

// Returns True only if the given path is a regular file.
inline is-regular-file(t: &string) -> bool

// Returns True only if the given path is a directory.
inline is-directory(t: &string) -> bool

// Creates a directory.
define create-directory(t: &string)[mode := 0o777] -> system(unit)

// Removes a file.
define unlink(path: &string) -> system(unit)

// Removes an empty directory.
define remove-empty-directory(path: &string) -> system(unit)

// Removes a directory recursively.
define remove-directory(dir-path: &string) -> system(unit)

// Returns the modification time of the given path.
define get-modification-time(path: &string) ->> system(time)
```
