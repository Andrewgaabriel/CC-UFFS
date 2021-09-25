module ula (
    input h,
    input [15:0] m2,
    input [15:0] m1,
    output [15:0] out
);

    assign out = h? m1 * m2 : m1 + m2;

endmodule