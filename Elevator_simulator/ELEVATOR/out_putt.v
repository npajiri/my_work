module out_put(w2, y2, w1,y1, Z);
	input w2, y2, w1,y1;
	output Z;
	
	
assign Z = ((~w2) & (~w1) & (~y2) & (~y1)) | ((~w2) & w1 & (~y2) & y1) | (w2 & (~w1) & y2 & (~y1)) | (w2 & w1 & y2 & y1);
	

endmodule 