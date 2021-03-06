SET(Bullet3Common_SRCS
	b3AlignedAllocator.cpp
	b3Vector3.cpp
	b3Logging.cpp
)

SET(Bullet3Common_HDRS
	b3Api.h
	Bullet3CommonApi.h
	b3AlignedAllocator.h
	b3AlignedObjectArray.h
	b3CommandLineArgs.h
	b3HashMap.h
	b3Logging.h
	b3Matrix3x3.h
	b3MinMax.h
	b3PoolAllocator.h
	b3QuadWord.h
	b3Quaternion.h
	b3Random.h
	b3Scalar.h
	b3StackAlloc.h
	b3Transform.h
	b3TransformUtil.h
	b3Vector3.h
	shared/b3Float4
	shared/b3Int2.h
	shared/b3Int4.h
	shared/b3Mat3x3.h
	shared/b3PlatformDefinitions
	shared/b3Quat.h
)

ADD_LIBRARY(Bullet3Common ${Bullet3Common_SRCS} ${Bullet3Common_HDRS})
TARGET_LINK_LIBRARIES(Bullet3Common PUBLIC BulletInterface)
SET_TARGET_PROPERTIES(Bullet3Common PROPERTIES VERSION ${BULLET_VERSION})
SET_TARGET_PROPERTIES(Bullet3Common PROPERTIES SOVERSION ${BULLET_VERSION})

IF(APPLE AND BUILD_SHARED_LIBS AND FRAMEWORK)
	BULLET3_INSTALL(TARGETS Bullet3Common EXPORT BulletLibsExport DESTINATION .)

	SET_TARGET_PROPERTIES(Bullet3Common PROPERTIES FRAMEWORK ON)
	SET_TARGET_PROPERTIES(Bullet3Common PROPERTIES PUBLIC_HEADER "${Bullet3Common_HDRS}")
ELSE()
	BULLET3_INSTALL(TARGETS Bullet3Common EXPORT BulletLibsExport
		RUNTIME DESTINATION ${BULLET_INSTALL_BINDIR}
		LIBRARY DESTINATION ${BULLET_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${BULLET_INSTALL_LIBDIR})
	BULLET3_INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		DESTINATION ${BULLET_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h" PATTERN "CMakeFiles" EXCLUDE)
ENDIF()
