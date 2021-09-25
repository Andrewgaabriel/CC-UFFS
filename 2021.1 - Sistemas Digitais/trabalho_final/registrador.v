module registrador (
    
    input sel,
    input [15:0] entrada,
    input clk,
    output reg [15:0] saida
);
    
    always @(posedge clk ) begin
        if (sel == 1) begin
            saida <= entrada;
        end
    end

endmodule