################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
nanopb/pb_decode.obj: C:/Users/chrisjohnson/Desktop/kitsune/third_party/nanopb/pb_decode.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.1.1/bin/armcl" -mv7M4 --float_support=fpalib --abi=eabi -me --include_path="C:/ti/ccsv5/tools/compiler/arm_5.1.1/include" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/nanopb" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/kitsune/protobuf" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/utils" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/source/portable/CCS/ARM_CM3/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/source/include/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/source/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/driverlib/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/simplelink/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/simplelink/Source/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/simplelink/Include/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/inc/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/kitsune/" -g --no_intrinsics --gcc --define=ccs --define=USE_FREERTOS --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="nanopb/pb_decode.pp" --obj_directory="nanopb" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

nanopb/pb_encode.obj: C:/Users/chrisjohnson/Desktop/kitsune/third_party/nanopb/pb_encode.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.1.1/bin/armcl" -mv7M4 --float_support=fpalib --abi=eabi -me --include_path="C:/ti/ccsv5/tools/compiler/arm_5.1.1/include" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/nanopb" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/kitsune/protobuf" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/utils" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/source/portable/CCS/ARM_CM3/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/source/include/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/source/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/third_party/FreeRTOS/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/driverlib/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/simplelink/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/simplelink/Source/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/simplelink/Include/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/inc/" --include_path="C:/Users/chrisjohnson/Desktop/kitsune/kitsune/" -g --no_intrinsics --gcc --define=ccs --define=USE_FREERTOS --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="nanopb/pb_encode.pp" --obj_directory="nanopb" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


