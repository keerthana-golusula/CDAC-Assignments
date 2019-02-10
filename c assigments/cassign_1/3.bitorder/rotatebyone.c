extern rot;
rotatebyone(num){
	int temp1,temp2;
	temp1 = (num&0x000f) << 12;
	temp2 = num >> 4;
	rot = temp1 | temp2;
}