

int i,j;
int main(){
 
	int k,ll,m,n,o,p;
 
	i = 1;
	println(i);
	
	j = 5 + 8;
	println(j);
	
	k = i + 2*j;
	println(k);

	m = k%9;
	println(m);
 
	n = m <= ll;
	println(n);
 
	o = i != j;
	println(o);
 
	p = n || o;
	println(p);
 
	p = n && o;
	println(p);
	
	p++;
	println(p);
 
	k = -p;
	println(k);

	if (k > 0 && p++ < 10) {
		println(i);
		i = i + p;
		println(i);
		int i;
		i = 20;
		println(i);

		{
			println(i);
			i = 7*i;
			println(i);
			i--;
			int i;
			i = 10;
			println(i);
		}
		println(i);
	}

    println(p);
	println(i);

	return 0;
}