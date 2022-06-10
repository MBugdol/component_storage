# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  component_storage_config = debug

else ifeq ($(config),release)
  component_storage_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := component_storage

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

component_storage:
ifneq (,$(component_storage_config))
	@echo "==== Building component_storage ($(component_storage_config)) ===="
	@${MAKE} --no-print-directory -C component_storage -f Makefile config=$(component_storage_config)
endif

clean:
	@${MAKE} --no-print-directory -C component_storage -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   component_storage"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"