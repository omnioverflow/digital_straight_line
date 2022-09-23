project(Core2D)

# ------------------------------------------------------------------------------

set(HEADER_FILES 
    public/core2d/ConvexPolygon.h
    public/core2d/DigitalSegment.h
    public/core2d/MBRegion.h
    public/core2d/Polygon.h
    public/core2d/Quad.h
    public/core2d/Triangle.h
    public/utils/Debugger.h
    public/utils/LineGenerator.h
)

set(IMPL_FILES
    impl/core2d/ConvexPolygon.cpp
    impl/core2d/DigitalSegment.cpp
    impl/core2d/MBRegion.cpp
    impl/core2d/Quad.cpp
    impl/core2d/Triangle.cpp
)

set(SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES})

# ------------------------------------------------------------------------------

add_library(Core2D STATIC ${SOURCE_FILES})
target_include_directories(
    Core2D
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/public
    ${CMAKE_CURRENT_SOURCE_DIR}/../third-party/boost/rational/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../third-party/boost/ublas/include
)

# ------------------------------------------------------------------------------