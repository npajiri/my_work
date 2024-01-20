module Decoder2to4(E, w1, w0, Y0, Y1, Y2, Y3);
	input E, w1, w0 ; 
	output Y0, Y1, Y2, Y3;
	
	
assign Y0 = (E & (~w1) & (~w0));
assign Y1 = (E & (~w1) & (w0));
assign Y2 = (E & (w1) & (~w0));
assign Y3 = (E & (w1) & (w0));
	
 
endmodule
  