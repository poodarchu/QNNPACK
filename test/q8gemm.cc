/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>

#include <cpuinfo.h>
#include <gemm-tester.h>
#include <qnnpack/q8gemm.h>

// clang-format off

#if CPUINFO_ARCH_ARM
  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_strided_a) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_strided_c) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_qmin128) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_qmax128) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_azp0) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_bzp0) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_eq_8_nozp) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(4)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
        }
      }
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
    }
  }

  TEST(Q8GEMM_4x8_AARCH32_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(4)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_4x8__aarch32_neon);
        }
      }
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_strided_a) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .aStride(37)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_strided_c) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .cStride(17)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_qmin128) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .qmin(128)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_qmax128) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .qmax(128)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_azp0) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_bzp0) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_eq_8_nozp) {
    GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(8)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .aStride(37)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .cStride(17)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .aZeroPoint(0)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .bZeroPoint(0)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .aZeroPoint(0)
          .bZeroPoint(0)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
              .mr(4)
              .nr(8)
              .np(8)
              .kr(2)
              .m(m)
              .n(n)
              .k(k)
              .iterations(3)
              .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .aStride(171)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
          .mr(4)
          .nr(8)
          .np(8)
          .kr(2)
          .m(4)
          .n(8)
          .k(k)
          .cStride(17)
          .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_AARCH32_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
              .mr(4)
              .nr(8)
              .np(8)
              .kr(2)
              .m(m)
              .n(n)
              .k(k)
              .iterations(3)
              .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__aarch32_neon, q8sumrows_ukernel_4x__neon);
        }
      }
    }
  }
#endif

#if CPUINFO_ARCH_ARM64
  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_strided_a) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_strided_c) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_qmin128) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_qmax128) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_azp0) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_bzp0) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_eq_8_nozp) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 8; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(8)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
        }
      }
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
    }
  }

  TEST(Q8GEMM_8x8_AARCH64_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 8; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(8)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_8x8__aarch64_neon);
        }
      }
    }
  }
#endif

#if CPUINFO_ARCH_ARM || CPUINFO_ARCH_ARM64
  TEST(Q8GEMM_4x8_NEON, k_eq_8) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_strided_a) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_strided_c) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_qmin128) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_qmax128) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_azp0) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_bzp0) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_eq_8_nozp) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(1)
      .m(4)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x8__neon);
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(4)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_4x8__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(1)
        .m(4)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_4x8__neon);
    }
  }

  TEST(Q8GEMM_4x8_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(4)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_4x8__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_strided_a) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_strided_c) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_qmin128) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_qmax128) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_azp0) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_bzp0) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_eq_8_nozp) {
    GemmTester()
      .mr(8)
      .nr(8)
      .np(8)
      .kr(1)
      .m(8)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_8x8__neon);
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 8; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(8)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_8x8__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(8)
        .nr(8)
        .np(8)
        .kr(1)
        .m(8)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_8x8__neon);
    }
  }

  TEST(Q8GEMM_8x8_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 8; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(8)
            .nr(8)
            .np(8)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_8x8__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_strided_a) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_strided_c) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_qmin128) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_qmax128) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_azp0) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_bzp0) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_eq_8_nozp) {
    GemmTester()
      .mr(6)
      .nr(4)
      .np(4)
      .kr(1)
      .m(6)
      .n(4)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_6x4__neon);
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 4; n++) {
          GemmTester()
            .mr(6)
            .nr(4)
            .np(4)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_6x4__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(6)
        .nr(4)
        .np(4)
        .kr(1)
        .m(6)
        .n(4)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_6x4__neon);
    }
  }

  TEST(Q8GEMM_6x4_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 6; m++) {
        for (uint32_t n = 1; n <= 4; n++) {
          GemmTester()
            .mr(6)
            .nr(4)
            .np(4)
            .kr(1)
            .m(m)
            .n(n)
            .k(k)
            .testMicroKernel(q8gemm_ukernel_6x4__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_strided_a) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_strided_c) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_qmin128) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_qmax128) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_azp0) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_bzp0) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_eq_8_nozp) {
    GemmTester()
      .mr(4)
      .nr(8)
      .np(8)
      .kr(2)
      .m(4)
      .n(8)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(4)
            .nr(8)
            .np(8)
            .kr(2)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
        }
      }
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(8)
        .np(8)
        .kr(2)
        .m(4)
        .n(8)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
    }
  }

  TEST(Q8GEMM_4x8c2_XZP_NEON, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 8; n++) {
          GemmTester()
            .mr(4)
            .nr(8)
            .np(8)
            .kr(2)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_xzp_ukernel_4x8c2__neon, q8sumrows_ukernel_4x__neon);
        }
      }
    }
  }
#endif

#if CPUINFO_ARCH_X86 || CPUINFO_ARCH_X86_64
  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_strided_a) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_strided_c) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_qmin128) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_qmax128) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_azp0) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_bzp0) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_eq_8_nozp) {
    GemmTester()
      .mr(2)
      .nr(4)
      .np(1)
      .kr(8)
      .m(2)
      .n(4)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 2; m++) {
        for (uint32_t n = 1; n <= 4; n++) {
          GemmTester()
            .mr(2)
            .nr(4)
            .np(1)
            .kr(8)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
        }
      }
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(2)
        .nr(4)
        .np(1)
        .kr(8)
        .m(2)
        .n(4)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
    }
  }

  TEST(Q8GEMM_2x4c8_SSE2, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 2; m++) {
        for (uint32_t n = 1; n <= 4; n++) {
          GemmTester()
            .mr(2)
            .nr(4)
            .np(1)
            .kr(8)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_2x4c8__sse2);
        }
      }
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_strided_a) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .aStride(37)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_strided_c) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .cStride(17)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_qmin128) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .qmin(128)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_qmax128) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .qmax(128)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_azp0) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .aZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_bzp0) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_eq_8_nozp) {
    GemmTester()
      .mr(4)
      .nr(4)
      .np(4)
      .kr(2)
      .m(4)
      .n(4)
      .k(8)
      .aZeroPoint(0)
      .bZeroPoint(0)
      .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8_strided_a) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .aStride(37)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8_strided_c) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8_azp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .aZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8_bzp0) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8_nozp) {
    for (size_t k = 9; k < 16; k++) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .aZeroPoint(0)
        .bZeroPoint(0)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_gt_8_subtile) {
    for (size_t k = 9; k < 16; k++) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 4; n++) {
          GemmTester()
            .mr(4)
            .nr(4)
            .np(4)
            .kr(2)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
        }
      }
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_div_8) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_div_8_strided_a) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .aStride(171)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_div_8_strided_c) {
    for (size_t k = 16; k < 128; k += 8) {
      GemmTester()
        .mr(4)
        .nr(4)
        .np(4)
        .kr(2)
        .m(4)
        .n(4)
        .k(k)
        .cStride(17)
        .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
    }
  }

  TEST(Q8GEMM_4x4c2_SSE2, k_div_8_subtile) {
    for (size_t k = 16; k < 128; k += 24) {
      for (uint32_t m = 1; m <= 4; m++) {
        for (uint32_t n = 1; n <= 4; n++) {
          GemmTester()
            .mr(4)
            .nr(4)
            .np(4)
            .kr(2)
            .m(m)
            .n(n)
            .k(k)
            .iterations(3)
            .testMicroKernel(q8gemm_ukernel_4x4c2__sse2);
        }
      }
    }
  }
#endif
