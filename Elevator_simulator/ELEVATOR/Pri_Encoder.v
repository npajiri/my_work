module pri_Encoder(X, Y);

input [3:0]Y;
output reg [1:0]X;

always@(Y)
begin 

casex(Y)

4'b0001:X = 2'b00;
4'b001x:X = 2'b10;
4'b01xx:X = 2'b01;
4'b1xxx:X = 2'b11;


endcase
end
endmodule