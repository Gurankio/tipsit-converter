#include "tui-100.c"

int main() {
  tui tui;

  tui_start(&tui, 50, 20, "Asdrubale");
  ansi_text_color(ANSI_RED); // Needs some fixing. But its pretty cool.
  tui_dlg_out(&tui, 10, 10, 25, 3, "Title", "Hello\nAsdf\nAS{%d}DFGHJK\nasd\nqwerty");
  // Cooler idea: one function when you find {%xx} you call vscanf(). void * should do the trick.

  int i;
  tui_dlg_in(&tui, 10, 10, 25, 3, "Title", "Hello World: ", "%d", &i);
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));
  tui_log_out(&tui, string_format("ASDF%d", i++));

  tui_confirm(&tui);
  tui_end(&tui);

  return 0;
}
