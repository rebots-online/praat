/* main_Praat.cpp
 *
 * Copyright (C) 1992-2008,2010-2021,2023,2024 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "../sys/praat.h"
#include "main_Praat.h"

static void logo (Graphics graphics) {
	Graphics_setWindow (graphics, 0.0, 1.0, 0.0, 0.8);
	Graphics_setGrey (graphics, 0.95);
	Graphics_fillRectangle (graphics, 0.0, 1.0, 0.0, 0.8);
	Graphics_setTextAlignment (graphics, Graphics_CENTRE, Graphics_HALF);
	Graphics_setFont (graphics, kGraphics_font::TIMES);
	Graphics_setFontSize (graphics, 45.0);
	Graphics_setColour (graphics, Melder_MAROON);
	Graphics_text (graphics, 0.385, 0.66, U"P");
	Graphics_text (graphics, 0.448, 0.66, U"\\s{R}");
	Graphics_text (graphics, 0.510, 0.66, U"\\s{A}");
	Graphics_text (graphics, 0.575, 0.66, U"\\s{A}");
	Graphics_text (graphics, 0.628, 0.66, U"\\s{T}");
	Graphics_setFontSize (graphics, 18.0);
	Graphics_text (graphics, 0.5, 0.53, U"%%doing phonetics by computer");
	Graphics_setFontSize (graphics, 14.0);
	Graphics_text (graphics, 0.5, 0.41, Melder_cat (U"version ", Melder_appVersionSTR(),
			U" (", Melder_appMonthSTR(), U" ", Melder_appDay(), U", ", Melder_appYear(), U")"));
	Graphics_setColour (graphics, Melder_BLACK);
	Graphics_setFont (graphics, kGraphics_font::HELVETICA);
	Graphics_setFontSize (graphics, 10.0);
	Graphics_text (graphics, 0.5, 0.20, Melder_cat (U"Copyright © 1992–", Melder_appYear(), U" by Paul Boersma and David Weenink"));
	Graphics_setFontSize (graphics, 10.0);
	Graphics_text (graphics, 0.5, 0.10, U"Website: https://www.fon.hum.uva.nl/praat or http://praat.org");
}

int main (int argc, char *argv []) {
	try {
		//TRACE
		praat_setLogo (130.0, 80.0, logo);
		Melder_stopwatch ();
		praat_init (U"" stringize (PRAAT_NAME),
			U"" stringize (PRAAT_VERSION_STR), PRAAT_VERSION_NUM,
			PRAAT_YEAR, PRAAT_MONTH, PRAAT_DAY,
			U"paul.boersma", U"uva.nl",
			argc, argv
		);
		trace (Melder_stopwatch ());
		INCLUDE_LIBRARY (praat_uvafon_init)
		trace (Melder_stopwatch ());
		praat_run ();
		trace (Melder_stopwatch ());
	} catch (MelderError) {
		Melder_flushError (U"This error message percolated all the way to the top.");   // an attempt to catch Apache errors
	}
	return 0;
}

/* End of file main_Praat.cpp */
