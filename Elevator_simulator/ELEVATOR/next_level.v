module next_level(a2, b2, a1, b1, Y2, Y1);
	input a2, b2, a1,b1;
	output Y2, Y1;
	
	
assign Y2 = (a2 & a1 & (((~b2) & (~b1)) | (b2 & b1))) | (a2 & (~a1) & (((~b2) & b1) | (b2 & (~b1))));
assign Y1 = ((~a2) & b2 & (~b1)) | ((~a2) & a1 & (~b2)) | (a2 & (~b2) & (~b1)) | (a2 & a1 & b2);
	
endmodule 
