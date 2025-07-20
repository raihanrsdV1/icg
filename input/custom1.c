int main()
{

	int i;
	i = -100;
	if ((i < 0 || i++ < 10) || (i < 0 && i > -10))
		i = i +100;
	else
		i =  i +200;
	println(i);

	return 0;
}