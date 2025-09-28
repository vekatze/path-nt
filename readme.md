# path

`path` is a library to perform path-related operations.

```sh
neut get path https://github.com/vekatze/path-nt/raw/main/archive/0-1-38.tar.zst
```

## Types

### Pure Operations

```neut
// is-absolute("/foo") => True
// is-absolute("bar/baz") => False
define is-absolute(path: &text): bool

// is-absolute("/foo") => False
// is-absolute("bar/baz") => True
define is-relative(path: &text): bool

// clean("foo/./bar//../buz.txt") => "foo/buz.txt"
define clean(path: &text): text

// append("test/sample", "foo.txt")      => "test/sample/foo.txt"
// append("test/sample/", "foo.txt")     => "test/sample/foo.txt"
// append("test/sample", "/foo.txt")     => "test/sample/foo.txt"
// append("test/sample/", "/foo.txt")    => "test/sample/foo.txt"
// append("test/.//sample/", "/foo.txt") => "test/sample/foo.txt"
define append(path1: &text, path2: &text): text

// take-last("test/sample/foo.txt") => "foo.txt"
// take-last("test/.//sample/foo.txt") => "foo.txt"
// take-last("test/sample/") => ""
define take-last(path: &text): text

// drop-last("test/sample/foo.txt") => "test/sample"
// drop-last("test/.//sample/foo.txt") => "test/sample"
// drop-last("test/sample/") => "test/sample"
define drop-last(path: &text): text

// split-extension("test/sample/foo.txt")     => Pair("test/sample/foo", ".txt")
// split-extension("test/.//sample/foo.txt")  => Pair("test/sample/foo", ".txt")
// split-extension("test/sample/foo")         => Pair("test/sample/foo", "")
// split-extension("test/sample/.foo")        => Pair("test/sample/.foo", "")
// split-extension("test/sample/.foo.tar.gz") => Pair("test/sample/.foo.tar", ".gz")
define split-extension(path: &text): pair(text, text)
```

### IO Operations

```neut
// A type for directory entries.
data dirent {
| Dirent(
    kind: dtype,
    name: text,
  )
}

// Returns the absolute path of the current directory.
define get-current-directory(): system(text)

// Reads the content of the given directory.
define read-directory(p: &text): system(list(dirent))
```
