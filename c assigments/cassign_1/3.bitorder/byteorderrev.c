extern int rev;
byteorderrev(num){
	int temp1, temp2;
	temp1 = num>>8;
	temp2 = ((num&0x00ff)<<8);
	rev = temp1 | temp2;
	return rev;
	
}