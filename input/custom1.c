int main()
{

	int i;

	if ((i > 0 && i < 10) || (i < 0 && i > -10))
		i = 100;
	else
		i = 200;
	printf(i);

	return 0;
}