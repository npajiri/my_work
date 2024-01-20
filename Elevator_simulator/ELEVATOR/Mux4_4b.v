module Mux4_4b(S1, S0, W0, W1, W2, W3, Z);
	input  S1, S0 ;
	input [3:0] W0, W1, W2, W3; 
	output [3:0] Z;
		
 reg [3:0] Z;
 
 always@(S1, S0, W0, W1, W2, W3)
 
 begin
 
 case({S1, S0})
 
 3'b00: Z = W0;
 3'b01: Z = W1;
 3'b10: Z = W2;
 3'b11: Z = W3;

 
 endcase
 end 
 endmodule
 