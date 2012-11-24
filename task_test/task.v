module main;
  integer val;
initial begin
  $task_test(99, val);
  $display("val=%d", val);
end
endmodule
