#include <dirent.h>

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
