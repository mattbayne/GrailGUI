set(grail-CAD
    Curve.cc
    Cylinder.cc
    RectangularPrism.cc
)

list(TRANSFORM grail-CAD PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)
set(grail-CAD ${grail-CAD} PARENT_SCOPE)