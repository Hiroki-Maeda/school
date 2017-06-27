/* 303 */
#include <stdio.h>
int main(void)
{
  int a, b;
  float fa, fb;
  double da, db;
  int wa, sa, seki, wari;
  float fwa, fsa, fseki, fwari;
double dwa, dsa, dseki, dwari;
  printf("int型\n");
  printf("一つ目の数を入力してください\n");
  scanf("%d", &a);
  printf("二つ目の数を入力してください\n");
  scanf("%d", &b);
  wa = a + b;
  sa = a - b;
  seki = a * b;
  wari = a / b;


  printf("intの和=%d\n", wa);
  printf("intの差=%d\n", sa);
  printf("intの積=%d\n", seki);
  printf("intの割=%d\n", wari);
  printf("float型\n");
  printf("一つ目の数を入力してください\n");
  scanf("%f",&fa);
  printf("二つ目の数を入力してください\n");
  scanf("%f", &fb);
   fwa = fa + fb;
  fsa = fa - fb;
  fseki = fa * fb;
  fwari = fa / fb;
 printf("floatの和=%f\n", fwa);
  printf("floatの差=%f\n", fsa);
  printf("floatの積=%f\n", fseki);
  printf("floatの割=%f\n", fwari);
	printf("double型");
  printf("一つ目の数を入力してください\n");
  scanf("%lf", &da);
  printf("二つ目の数を入力してください\n");
  scanf("%lf", &db);

  dwa = da + db;
  dsa = da - db;
  dseki = da * db;
  dwari = da / db;
  printf("doubleの和=%f\n", dwa);
  printf("doubleの差=%f\n", dsa);
  printf("doubleの積=%f\n", dseki);
  printf("doubleの割=%f\n", dwari);
  return 0;
}
