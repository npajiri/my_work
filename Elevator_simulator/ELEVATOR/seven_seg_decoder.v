module seven_seg_decoder(x3, x2, x1, x0, Enable, A, B, C, D, E, F, G);
	input x3, x2, x1, x0, Enable;
	output A, B, C, D, E, F, G;
	reg A, B, C, D, E, F, G;
	
	
	always @(Enable or x3 or x2 or x1 or x0)
	
	begin 
	
		case ({Enable, x3, x2, x1, x0})
				
				5'b00000: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00001: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00010: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00011:begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00100: begin 
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00101:begin 
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00110: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b00111: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01000: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01001: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01010: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01011: begin 
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01100: begin 
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01101: begin 
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01110: begin
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				5'b01111: begin 
				A = 'b1; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b1; 
				F = 'b1; 
				G = 'b1;
				end
				
				// Enable =1
				5'b10000: begin
				A = 'b0;
				B = 'b0; 
				C = 'b0;
				D = 'b0; 
				E = 'b0;
				F = 'b0; 
				G = 'b1;
				end
				
				5'b10001: begin
				A = 'b1;
				B = 'b0;
				C = 'b0; 
				D = 'b1;
				E = 'b1;
				F = 'b1; 
				G = 'b1;
				end
				
				5'b10010: begin
				A = 'b0; 
				B = 'b0; 
				C = 'b1; 
				D = 'b0; 
				E = 'b0;
				F = 'b1;
				G = 'b0;
				end
				
				5'b10011:begin
				A = 'b0; 
				B = 'b0; 
				C = 'b0;
				D = 'b0;
				E = 'b1;
				F = 'b1;
				G = 'b0;
				end
				
				5'b10100: begin 
				A = 'b1; 
				B = 'b0;
				C = 'b0;
				D = 'b1;
				E = 'b1;
				F = 'b0;
				G = 'b0;
				end
				
				5'b10101:begin 
				A = 'b0;
				B = 'b1;
				C = 'b0;
				D = 'b0;
				E = 'b1;
				F = 'b0;
				G = 'b0;
				end
				
				5'b10110: begin
				A = 'b0;
				B = 'b1;
				C = 'b0;
				D = 'b0;
				E = 'b0;
				F = 'b0;
				G = 'b0;
				end
				
				5'b10111: begin
				A = 'b0;
				B = 'b0; 
				C = 'b0;
				D = 'b1;
				E = 'b1;
				F = 'b1;
				G = 'b1;
				end
				
				5'b11000: begin
				A = 'b0; 
				B = 'b0;
				C = 'b0; 
				D = 'b0;
				E = 'b0;
				F = 'b0; 
				G = 'b0;
				end
				
				5'b11001: begin
				A = 'b0; 
				B = 'b0;
				C = 'b0;
				D = 'b0;
				E = 'b1;
				F = 'b0;
				G = 'b0;
				end
				
				5'b11010: begin
				A = 'b0; 
				B = 'b0;
				C = 'b0; 
				D = 'b1;
				E = 'b0;
				F = 'b0; 
				G = 'b0;
				end
				
				5'b11011: begin 
				A = 'b1;
				B = 'b1;
				C = 'b0; 
				D = 'b0; 
				E = 'b0;
				F = 'b0;
				G = 'b0;
				end
				
				5'b11100: begin 
				A = 'b0; 
				B = 'b1;
				C = 'b1;
				D = 'b0;
				E = 'b0;
				F = 'b0;
				G = 'b1;
				end
				
				5'b11101: begin 
				A = 'b1; 
				B = 'b0;
				C = 'b0; 
				D = 'b0; 
				E = 'b0;
				F = 'b1;
				G = 'b0;
				end
				
				5'b11110: begin
				A = 'b0;
				B = 'b1; 
				C = 'b1;
				D = 'b0; 
				E = 'b0;
				F = 'b0;
				G = 'b0;
				end

				5'b11111: begin 
				A = 'b0; 
				B = 'b1; 
				C = 'b1; 
				D = 'b1; 
				E = 'b0; 
				F = 'b0; 
				G = 'b0;
				end
				
			endcase
	
	end
	
		
		endmodule
		
	