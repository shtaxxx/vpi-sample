#include <vpi_user.h>

static int task_compiletf(char*user_data)
{
  return 0;
}

static int task_calltf(char*user_data)
{
  vpiHandle	vhandle, iterator, inhandle, outhandle;
	s_vpi_value	inval, outval;
	int	din, dout;
	vhandle = vpi_handle(vpiSysTfCall, NULL);
	iterator = vpi_iterate(vpiArgument, vhandle);
	inhandle = vpi_scan(iterator);
  outhandle = vpi_scan(iterator);

	inval.format = vpiIntVal;
	vpi_get_value(inhandle, &inval);
	din = inval.value.integer;

  vpi_printf("din=%d\n", din);
  dout = din * 2;

	outval.format = vpiIntVal;
	outval.value.integer = dout;
  vpi_put_value(outhandle, &outval, NULL, vpiNoDelay);

  return 0;
}

void task_register()
{
      s_vpi_systf_data tf_data;
      tf_data.type        = vpiSysTask;
      tf_data.tfname    = "$task_test";
      tf_data.calltf    = task_calltf;
      tf_data.compiletf = task_compiletf;
      tf_data.sizetf    = 0;
      tf_data.user_data = 0;
      vpi_register_systf(&tf_data);
}

void (*vlog_startup_routines[])() = {
    task_register,
    0
};
