module main;
  integer val;
initial begin
  val = $func_test(99);
  $display("val=%d", val);
end
endmodule
