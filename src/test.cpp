#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <Python.h>

using namespace std;
namespace py = boost::python;
namespace np = boost::numpy;

void print_numpy_array(py::object const &o);

int main() {
  Py_Initialize();
  np::initialize();
  py::object main_module = py::import("__main__");
  py::object main_ns     = main_module.attr("__dict__");
  py::object sys_module  = py::import("sys");
  sys_module.attr("path").attr("insert")(0, "../python/");
  py::object mod = py::import("mod");

  // py::object result = mod.attr("test_fn")(10);
  // int n = py::extract<int>(result);
  // cout << "Result = " << n << endl;
  py::object result = mod.attr("test_numpy")(7.77);
  print_numpy_array(result);

  return 0;
}

void print_numpy_array(py::object const &o) {
  np::ndarray npo = np::from_object(o);
  if(npo.get_nd() != 1) {
    cout << "# dims must be 1" << endl;
    return;
  }
  if(npo.get_dtype() != np::dtype::get_builtin<double>()) {
    cout << "dtype must be double" << endl;
    return;
  }
  unsigned int size = npo.shape(0), stride = npo.strides(0);
  vector<double> data(size);
  char *data_ptr = npo.get_data();
  for(unsigned int i = 0; i < size; i++) {
    data[i] = *(reinterpret_cast<double *>(data_ptr + i*stride));
    cout << data[i] << " ";
  }
  cout << endl;
}
