void fun()
{
static int a = 0;
a+=2;
printf("%d",a);
}
main()
{
int cc;
for(cc=1;cc<4;cc++)
fun();
printf("\n");
}