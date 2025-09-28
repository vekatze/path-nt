#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>

__attribute__((always_inline)) char *
neut_path_v0_1_GET_DNAME(struct dirent *d) {
  return d->d_name;
}

__attribute__((always_inline)) __uint8_t
neut_path_v0_1_GET_DTYPE(struct dirent *d) {
  return d->d_type;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_UNKNOWN() {
  return DT_UNKNOWN;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_FIFO() {
  return DT_FIFO;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_CHR() {
  return DT_CHR;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_DIR() {
  return DT_DIR;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_BLK() {
  return DT_BLK;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_REG() {
  return DT_REG;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_LNK() {
  return DT_LNK;
}

__attribute__((always_inline)) __uint8_t neut_path_v0_1_DT_SOCK() {
  return DT_SOCK;
}

int64_t neut_path_v0_1_is_regular_file(const char *path) {
  struct stat st;
  if (stat(path, &st) != 0) {
    return false;
  }
  return S_ISREG(st.st_mode) ? 1 : 0;
}

int64_t neut_path_v0_1_is_directory(const char *path) {
  struct stat st;
  if (stat(path, &st) != 0) {
    return false;
  }
  return S_ISDIR(st.st_mode) ? 1 : 0;
}

int64_t neut_path_v0_1_mkdir(const char *path, mode_t mode) {
  return (int64_t)mkdir(path, mode);
}

int64_t neut_path_v0_1_get_modification_time(const char *path, int64_t *sec,
                                             int64_t *nsec) {
  struct stat st;
  if (stat(path, &st) != 0) {
    return -1;
  }

  *sec = (int64_t)st.st_mtime;
#if defined(__APPLE__)
  *nsec = st.st_mtimespec.tv_nsec;
#elif defined(st_mtim) ||                                                      \
    (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200809L)
  *nsec = st.st_mtim.tv_nsec;
#else
  *nsec = 0;
#endif
  return 0;
}
