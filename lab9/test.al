int y, z;
int main(void)
begin
	int x;
	int y;
	boolean a;
	x = 5;
	write x;
	write ",";
	write 6/2;
	write ",";
	if (x != 5) then write 7;
	else write "false";
	while (x > 1) do x = x - 1;
	write x;
	a = true;
	write a;
	a = not a;
	write a;
end