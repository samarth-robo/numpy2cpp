#include <boost/python.hpp>
#include <boost/numpy.hpp>
#include <Python.h>

using namespace std;
namespace py = boost::python;
namespace np = boost::numpy;

void print_numpy_array(py::object const &o);

int main() {
  // initialize
  Py_Initialize();
  np::initialize();

  // add ../python to Python system path
  py::object sys_module  = py::import("sys");
  sys_module.attr("path").attr("insert")(0, "../python/");

  // import our test module from ../python
  py::object mod = py::import("mod");

  // use if python function returns a scalar
  // py::object result = mod.attr("test_fn")(10);
  // int n = py::extract<int>(result);
  // cout << "Result = " << n << endl;

  // use if python function returns a numpy ndarray
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
