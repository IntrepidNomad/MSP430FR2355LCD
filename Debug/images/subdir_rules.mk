################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
images/%.obj: ../images/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"/home/intrepidnomad/AUR/ccstudio/src/installdir/opt/ccstudio/ccs/tools/compiler/ti-cgt-msp430_18.12.2.LTS/bin/cl430" -vmspx --use_hw_mpy=F5 --include_path="/home/intrepidnomad/AUR/ccstudio/src/installdir/opt/ccstudio/ccs/ccs_base/msp430/include" --include_path="/home/intrepidnomad/workspace_v9/MSP430FR2355LCD" --include_path="/home/intrepidnomad/AUR/ccstudio/src/installdir/opt/ccstudio/ccs/tools/compiler/ti-cgt-msp430_18.12.2.LTS/include" --include_path="/home/intrepidnomad/workspace_v9/MSP430FR2355LCD/GrLib/grlib" --include_path="/home/intrepidnomad/workspace_v9/MSP430FR2355LCD/GrLib/fonts" --include_path="/home/intrepidnomad/workspace_v9/MSP430FR2355LCD/images" --include_path="/home/intrepidnomad/workspace_v9/MSP430FR2355LCD/LcdDriver" --include_path="/home/intrepidnomad/workspace_v9/MSP430FR2355LCD/MSP430FR2xx_4xx" --advice:power=all --advice:hw_config=all --define=__MSP430FR2355__ --define=_FRWP_ENABLE --define=_INFO_FRWP_ENABLE -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="images/$(basename $(<F)).d_raw" --obj_directory="images" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


