#include <pybind11/pybind11.h>
namespace py = pybind11;

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    // m.def("add", &add, "A function that adds two numbers",
    //       py::arg("i"), py::arg("j"));
    m.def("add", &add, "A function which adds two numbers",
          py::arg("i") = 1, py::arg("j") = 2);
    py::object world = py::cast("World");
    m.attr("world") = world;
}