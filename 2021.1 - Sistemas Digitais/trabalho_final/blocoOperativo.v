`include "mux4x1.v"
`include "ula.v"
`include "registrador.v"


module blocoOperativo (

    /* valores: */
    input [7:0] X,
    input [15:0] A,
    input [15:0] B,
    input [15:0] C,

    /* controladores dos mux: */
    input [1:0] M0,
    input [1:0] M1,
    input [1:0] M2,

    /* carregadores dos regs: */
    input LX,
    input LS,
    input LH,

    /* controlador ULA: */
    input h,

    /* clock */
    input clk,

    /* resultado: */
    output [15:0] resultado
);

/* ligações:  */

    wire [15:0] saida_LX;
    wire [15:0] saida_LS;
    wire [15:0] saida_LH;
    wire [15:0] saida_MuxM0;
    wire [15:0] saida_MuxM1;
    wire [15:0] saida_MuxM2;
    wire [15:0] saida_ULA;
    wire [15:0] saida_X16bits;
    wire [15:0] op1_MuxM0;

    assign saida_X16bits = X;
    assign op1_MuxM0 = 0;




    //instanciamentos:

    ula ula0(h, saida_MuxM2, saida_MuxM1, saida_ULA);
 
    mux4x1 m0(M0, op1_MuxM0, A, B, C, saida_MuxM0);
    mux4x1 m1(M1, saida_MuxM0, saida_X16bits, saida_LS, saida_LH, saida_MuxM1);
    mux4x1 m2(M2, saida_X16bits, saida_MuxM0, saida_LS, saida_LH, saida_MuxM2);

    registrador reg_LX(LX, saida_X16bits, clk, saida_LX);
    registrador reg_LS(LS, saida_ULA, clk, saida_LS);
    registrador reg_LH(LH, saida_ULA, clk, saida_LH);


    assign resultado = saida_LS;

endmodule