int y, z;
int whatdoicallthis[10];
int main(void)
begin
	int x;
	int y;
	int i;
	boolean a;
	boolean b;
	boolean c;
	boolean d;
	boolean e;
	x = 10;
	write x;
	write "\n";
	write "Math operations testing: plus minus multiplication division";
	write "\n";
	write "6+2 & 6-2 & 6*2 & 6/2";
	write "\n";
	write 6+2;
	write "\n";
	write 6-2;
	write "\n";
	write 6*2;
	write "\n";
	write 6/2;
	write "\n";
	write "Enter a number. Enter number greater than or equal to 5 to test positive condition, and number less than 5 to test false condition.";
	write "\n";
	read y;
	i = 0;
	if (y >= 5) then 
		begin
			write "Test passed for true condition.";
			write "\n";
		end
	else write "Test passed for false condition.";
	write "\n";
	while (x > 0) do 
		begin
		write "Value at index ";
		write i;
		write ": ";
		x = x - 1;
		whatdoicallthis[i] = x;
		write whatdoicallthis[i];
		write "\n";
		i = i + 1;
		end
	a = true;
	write "Original boolean value before testing 'not' operator: ";
	write a;
	write "\n";
	write "Testing 'not' operation; expected value is 0: ";
	a = not a;
	write a;
	write "\n";
	c = true;
	b = false;
	write "\n";
	write "Testing 'and' operation; expected value is 0: ";
	d = c and b;
	write d;
	write "\n";
	write "Testing 'or' operation; expected value is 1: ";
	e = c or b;
	write e;
	write "\n";
end
