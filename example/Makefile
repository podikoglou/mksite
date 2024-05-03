# settings
PAGES_DIR = ./pages
TEMPLATES_DIR = ./templates
ASSETS_DIR = ./assets
OUT_DIR = ./out

# find targets
PAGES := $(shell find $(PAGES_DIR) -type f -name '*.md')
TEMPLATES := $(shell find $(TEMPLATES_DIR) -type f -name '*.html')
ASSETS := $(shell find $(ASSETS_DIR) -type f)

OUTPUTS := $(patsubst $(PAGES_DIR)/%.md,$(OUT_DIR)/%.html,$(PAGES))

all: $(OUTPUTS) copy-assets

# todo: find a way so that this doesnt execute EVERY time make is ran
copy-assets:
	@cp -v $(ASSETS) $(OUT_DIR)

$(OUT_DIR)/%.html: $(PAGES_DIR)/%.md
	@mkdir -p $(dir $@)
	mksite --template templates/page.html < $< > $@

clean:
	rm -rfv $(OUT_DIR)

.PHONY: all clean
