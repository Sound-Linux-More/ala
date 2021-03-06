#ifndef ALAUTILITY_H_INCLUDED
#define ALAUTILITY_H_INCLUDED

#include <stdint.h>

/* 円周率 */
#define ALA_PI              3.1415926535897932384626433832795029

/* 未使用引数 */
#define ALAUTILITY_UNUSED_ARGUMENT(arg)  ((void)(arg))
/* 算術右シフト */
#if ((((int32_t)-1) >> 1) == ((int32_t)-1))
/* 算術右シフトが有効な環境では、そのまま右シフト */
#define ALAUTILITY_SHIFT_RIGHT_ARITHMETIC(sint32, rshift) ((sint32) >> (rshift))
#else
/* 算術右シフトが無効な環境では、自分で定義する ハッカーのたのしみのより引用 */
/* 注意）有効範囲:0 <= rshift <= 32 */
#define ALAUTILITY_SHIFT_RIGHT_ARITHMETIC(sint32, rshift) \
  ((((uint64_t)(sint32) + 0x80000000UL) >> (rshift)) - (0x80000000UL >> (rshift)))
#endif
/* 最大値の取得 */
#define ALAUTILITY_MAX(a,b) (((a) > (b)) ? (a) : (b))
/* 最小値の取得 */
#define ALAUTILITY_MIN(a,b) (((a) < (b)) ? (a) : (b))
/* 最小値以上最小値以下に制限 */
#define ALAUTILITY_INNER_VALUE(val, min, max) (ALAUTILITY_MIN((max), ALAUTILITY_MAX((min), (val))))
/* 符号付き32bit数値を符号なし32bit数値に一意変換 */
#define ALAUTILITY_SINT32_TO_UINT32(sint) (((int32_t)(sint) < 0) ? ((uint32_t)((-((sint) << 1)) - 1)) : ((uint32_t)(((sint) << 1))))
/* 符号なし32bit数値を符号付き32bit数値に一意変換 */
#define ALAUTILITY_UINT32_TO_SINT32(uint) ((int32_t)((uint) >> 1) ^ -(int32_t)((uint) & 1))

#ifdef __cplusplus
extern "C" {
#endif

/* 窓の適用 */
void ALAUtility_ApplyWindow(const double* window, double* data, uint32_t num_samples);

/* サイン窓を作成 */
void ALAUtility_MakeSinWindow(double* window, uint32_t window_size);

/* ceil(log2(val))の計算 */
uint32_t ALAUtility_Log2Ceil(uint32_t val);

/* floor(log2(val))の計算 */
uint32_t ALAUtility_Log2Floor(uint32_t val);

/* 2の冪乗に切り上げる */
uint32_t ALAUtility_RoundUp2Powered(uint32_t val);

/* round関数（C89で定義されてない） */
double ALAUtility_Round(double d);

#ifdef __cplusplus
}
#endif

#endif /* ALAUTILITY_H_INCLUDED */
