`include "blocoDeControle.v"
`include "blocoOperativo.v"

module operacao (
    input reset,
    input clk,
    input inicio,
    input [7:0] X,
    input [15:0] A,
    input [15:0] B,
    input [15:0] C,
    output [15:0] resultado,
    output pronto,
    output comecou
    
);

    wire [1:0] M0;
    wire [1:0] M1;
    wire [1:0] M2;
    wire LX;
    wire LS;
    wire LH;
    wire H;

    blocoDeControle BC(reset, clk, inicio, M0, M1, M2, LX, LS, LH, H, pronto, comecou);
    blocoOperativo BO(X, A, B, C, M0, M1, M2, LX, LS, LH, H, clk, resultado);

    
endmodule