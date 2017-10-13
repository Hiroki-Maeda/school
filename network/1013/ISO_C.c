#include <stdio｡h>

int main(void) {
 #ifdef __STDC__
 #if defined(__STDC_VERSION__) && __STDC_VERSION__>=199901L
 /* C99以後ﾆ対応ｼﾃｲﾙ */
 printf("ｺﾝﾊﾟｲﾗﾊ､C99ﾆ対応ｼﾃｲﾙ(ﾊﾞｰｼﾞｮﾝ:%ld)｡\n"､ __STDC_VERSION__);
 #elif defined(__STDC_VERSION__) && __STDC_VERSION__>=199409L
  /* C95ﾆ対応ｼﾃｲﾙｶﾞ､C99ﾆ対応ｼﾃｲﾅｲ */
 printf("ｺﾝﾊﾟｲﾗﾊ､C95ﾆ対応ｼﾃｲﾙ(ﾊﾞｰｼﾞｮﾝ:%ld)｡\n"､ __STDC_VERSION__);
 #else
 /* C89ﾀﾞｹﾆ対応ｼﾃｲﾙ */
 printf("ｺﾝﾊﾟｲﾗﾊ､C89ﾆ対応ｼﾃｲﾙ｡\n");
 #endif
 #else
 /* ISO Cﾆ対応ｼﾃｲﾅｲ */
 printf("ｺﾝﾊﾟｲﾗﾊ､ISO Cﾉ標準ﾆ対応ｼﾃｲﾅｲ｡\n");
 #endif

 return 0;

｝
