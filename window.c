#include <gtk/gtk.h>
#include <string.h>

#define DefaultNoOfUnits 8

// Define the student struct
typedef struct {
    char studentName[23];
    char studentId[12];
    char courseName[50];
	char grade[4];
    int no_of_units;
    char unit_names[8][50];
    int unit_marks[8];
    GtkWidget *name_entry;
    GtkWidget *id_entry;
    GtkWidget *course_entry;
    GtkWidget *no_of_units_entry;
    GtkWidget *unit_entry[8];
    GtkWidget *mark_entry[8];
	
	// Define a struct to hold subject information
	struct SubjectInfo{
		char subject_name[50];
		double marks;

	};

	
} Student;

typedef struct {
		GtkWidget *grid;
		GtkWidget *window;
		Student *student;
	} Widgets;


// Callback function for the "Save" button
void save_button_clicked(GtkButton *button, gpointer data) {
	
	Widgets *widgets = (Widgets *)data;
	GtkWidget *window = widgets->window;
	Student *student = 	widgets->student;
	
	GtkWidget *second_window;
    GtkWidget *label;
	GtkWidget *btn;
	
	
	// Get text from input fields
    const gchar *name = gtk_entry_get_text(GTK_ENTRY(student->name_entry));
    const gchar *id = gtk_entry_get_text(GTK_ENTRY(student->id_entry));
    const gchar *course = gtk_entry_get_text(GTK_ENTRY(student->course_entry));
    const gchar *no_of_units_text = gtk_entry_get_text(GTK_ENTRY(student->no_of_units_entry));
	
	// Copy input to the struct
    strncpy(student->studentName, name, sizeof(student->studentName));
    strncpy(student->studentId, id, sizeof(student->studentId));
    strncpy(student->courseName, course, sizeof(student->courseName));
	student->no_of_units = atoi(no_of_units_text);
	int units = atoi(no_of_units_text);
	
	// Collect unit names and marks
    for (int i = 0; i < DefaultNoOfUnits; i++) {
        const gchar *unit_name = gtk_entry_get_text(GTK_ENTRY(student->unit_entry[i]));
        const gchar *mark_text = gtk_entry_get_text(GTK_ENTRY(student->mark_entry[i]));

        strncpy(student->unit_names[i], unit_name, sizeof(student->unit_names[i]));
        student->unit_marks[i] = atoi(mark_text);
    }
		
    // Convert number of units to an integer
    //student->no_of_units = strtol(no_of_units_text, NULL, 10);

	
	    // Calculate total marks, average, highest scored unit, least scored unit
    int total_marks = 0;
    int highest_mark = -1;
    int lowest_mark = 101; // Initialize with a value greater than the maximum possible mark

    for (int i = 0; i < DefaultNoOfUnits; i++) {
        total_marks += student->unit_marks[i];
        if (student->unit_marks[i] > highest_mark) {
            highest_mark = student->unit_marks[i];
        }
        if (student->unit_marks[i] < lowest_mark) {
            lowest_mark = student->unit_marks[i];
        }
    }
	

    double avg = (double)total_marks / DefaultNoOfUnits;
	
	
	if (avg >= 90) strcpy(student->grade, "A");
    else if (avg >= 80) strcpy(student->grade,"B");
    else if (avg >= 70) strcpy(student->grade, "C");
    else if (avg >= 60) strcpy(student->grade, "D");
    else strcpy(student->grade, "F");
	
		
	/////////////////////////
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<STUDENT RESULT SLIP>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
        printf("************************************************************************************* \n");

    // Print the captured data (you can modify this to save to a file or display in a new window)
    g_print("Student Name: %s\n", student->studentName);
    g_print("Student ID: %s\n", student->studentId);
    g_print("Course Name: %s\n", student->courseName);
    g_print("Number of Units: %d\n", student->no_of_units);
	
	printf("************************************************************************************* \n");
        printf("\n");
    for (int i = 0; i < DefaultNoOfUnits; i++) {
        g_print("Unit Name: %s\n", student->unit_names[i]);
        g_print("Unit Marks: %d\n", student->unit_marks[i]);
    }
	printf("************************************************************************************* \n");
        printf("\n");

    g_print("Highest Scoring Unit: %d\n", highest_mark);
    g_print("Lowest Scoring Unit: %d\n", lowest_mark);
        printf("************************************************************************************* \n");
        printf("\n");
	g_print("Total Marks: %d\n", total_marks);
    g_print("Average: %.2f\n", avg);
	g_print("Grade: %s\n", student->grade);
	
        printf("************************************************************************************* \n");
        printf("\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<STUDENT RESULT SLIP END>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");

	
	// Create the second window
    second_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(second_window), "Student's Result Slip");
    gtk_container_set_border_width(GTK_CONTAINER(second_window), 10);
    gtk_widget_set_size_request(second_window, 300, 500);
	
	// Create a scrolled window
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(second_window), scrolled_window);
	
	
	// Create a box for layout
    GtkWidget *statistics_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(scrolled_window), statistics_box);
	
	// Create a label for the second window
    label = gtk_label_new("<<<STUDENT RESULT SLIP>>>");
	
	// Create a button
    btn = gtk_button_new_with_label("New Record");
	
	// Add widgets to the box
    //gtk_box_pack_start(GTK_BOX(statistics_box), label, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(statistics_box), label);
	gtk_container_add(GTK_CONTAINER(statistics_box), btn);

	// Show all widgets
    //gtk_widget_show_all(second_window);

    // Close the first window
    //gtk_widget_destroy(GTK_WIDGET(window));
	
		//Create a student struct to store the data
	//Student student;
    
	// Create a grid to organize the subject input fields
    GtkWidget *grid_x = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid_x), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid_x), 10);
	
	// Create unit name and mark entry fields
		GtkWidget *unit_label;
		GtkWidget *mark_label;
    for (int i = 0; i < DefaultNoOfUnits; i++) {
		
		// Create a new row for the subject input
		GtkWidget *grid = GTK_WIDGET(grid_x);
		
		// Format the calculated values as strings
		char name_txt[100];
		char marks_txt[100];
		
		snprintf(name_txt, sizeof(name_txt),"Unit Name: %s", student->unit_names[i]);
		snprintf(marks_txt, sizeof(marks_txt), "Unit Marks: %d", student->unit_marks[i]);
    
        unit_label = gtk_label_new(NULL);
        mark_label = gtk_label_new(NULL);

		// Set the label texts
		gtk_label_set_text(GTK_LABEL(unit_label), name_txt);
		gtk_label_set_text(GTK_LABEL(mark_label), marks_txt);
		
        gtk_grid_attach(GTK_GRID(grid), unit_label, 0, i + 1, 1, 1);
		gtk_grid_attach(GTK_GRID(grid), mark_label, 1, i + 1, 1, 1);

    }

	
	// Add the grid to the box at the end (bottom) of the box
	gtk_box_pack_start(GTK_BOX(statistics_box), grid_x, TRUE, TRUE, 0);
	
	
	//Create labels to display student details
	// Create labels to display the calculated statistics
    GtkWidget *student_name_label = gtk_label_new(NULL);
    GtkWidget *student_id_label = gtk_label_new(NULL);
    GtkWidget *student_course_label = gtk_label_new(NULL);
	
	char name_text[100];
    char id_text[100];
	char course_text[100];
	
	snprintf(name_text, sizeof(name_text),"Student Name: %s", student->studentName);
    snprintf(id_text, sizeof(id_text),"Student ID: %s", student->studentId);
    snprintf(course_text, sizeof(course_text), "Course Name: %s", student->courseName);
	
	gtk_label_set_text(GTK_LABEL(student_name_label), name_text);
    gtk_label_set_text(GTK_LABEL(student_id_label), id_text);
    gtk_label_set_text(GTK_LABEL(student_course_label), course_text);



    // Add the student details to the statistics box
    gtk_container_add(GTK_CONTAINER(statistics_box), student_name_label);
    gtk_container_add(GTK_CONTAINER(statistics_box), student_id_label);
    gtk_container_add(GTK_CONTAINER(statistics_box), student_course_label);
	
	// Create labels to display the calculated statistics
    GtkWidget *average_label = gtk_label_new(NULL);
    GtkWidget *total_marks_label = gtk_label_new(NULL);
    GtkWidget *least_scored_label = gtk_label_new(NULL);
    GtkWidget *most_scored_label = gtk_label_new(NULL);

    // Format the calculated values as strings
    char average_text[100];
    char total_marks_text[100];
    char least_scored_text[100];
    char most_scored_text[100];
	char grade_text[100];

    snprintf(average_text, sizeof(average_text), "Average: %.2f", avg);
    snprintf(total_marks_text, sizeof(total_marks_text), "Total Marks: %d", total_marks);
    snprintf(least_scored_text, sizeof(least_scored_text), "Least Scored Subject: %d", lowest_mark);
    snprintf(most_scored_text, sizeof(most_scored_text), "Most Scored Subject: %d", highest_mark);
	snprintf(grade_text, sizeof(grade_text), "Grade: %d", student->grade);

	
    // Set the label texts
    gtk_label_set_text(GTK_LABEL(average_label), average_text);
    gtk_label_set_text(GTK_LABEL(total_marks_label), total_marks_text);
    gtk_label_set_text(GTK_LABEL(least_scored_label), least_scored_text);
    gtk_label_set_text(GTK_LABEL(most_scored_label), most_scored_text);

	
    // Add the new labels to the statistics box
    gtk_container_add(GTK_CONTAINER(statistics_box), average_label);
    gtk_container_add(GTK_CONTAINER(statistics_box), total_marks_label);
    gtk_container_add(GTK_CONTAINER(statistics_box), least_scored_label);
    gtk_container_add(GTK_CONTAINER(statistics_box), most_scored_label);


    // Show all widgets
    gtk_widget_show_all(second_window);

	
	// Close the first window
    //gtk_widget_destroy(GTK_WIDGET(window));

}


// Function to quit the program
void on_quit_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();  // Quit the GTK main loop and close the program
}

int main(int argc, char *argv[]) {
	// Initialize GTK
    gtk_init(&argc, &argv);
	
	//Create a student struct to store the data
	Student student;

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Student Details");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	// Create a scrolled window
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    // Create a box for layout
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(scrolled_window), box);

    // Create input fields for student details
    GtkWidget *name_label = gtk_label_new("Student Name:");
    GtkWidget *name_entry = gtk_entry_new();

    GtkWidget *id_label = gtk_label_new("Student ID:");
    GtkWidget *id_entry = gtk_entry_new();

    GtkWidget *course_label = gtk_label_new("Course Name:");
    GtkWidget *course_entry = gtk_entry_new();

    GtkWidget *no_of_units_label = gtk_label_new("Did the student miss any units? \n Input the Number of Missed Units:");
    GtkWidget *no_of_units_entry = gtk_entry_new();
	
	// Add widgets to the box
    gtk_box_pack_start(GTK_BOX(box), name_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), name_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), id_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), id_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), course_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), course_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), no_of_units_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), no_of_units_entry, FALSE, FALSE, 0);
	
	// Separator
    GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(box), separator, FALSE, FALSE, 0);
	
	// Create a grid to organize the subject input fields
    GtkWidget *grid_x = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid_x), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid_x), 10);

	GtkWidget *label;
	GtkWidget *marks_label;
	for (int i = 0; i < DefaultNoOfUnits; i++) {
		// Create a new row for the subject input
		GtkWidget *grid = GTK_WIDGET(grid_x);
		
		// Create a label for the subject name
		char label_text[20];
		snprintf(label_text, sizeof(label_text), "Subject %d:", i + 1);
		label = gtk_label_new(label_text);
		gtk_grid_attach(GTK_GRID(grid), label, 0, i + 1, 1, 1);

		// Create a text entry field for the subject name
		student.unit_entry[i] = gtk_entry_new();
		gtk_grid_attach(GTK_GRID(grid), student.unit_entry[i], 1, i + 1, 1, 1);

		// Create a  label for the marks
		marks_label = gtk_label_new("Marks:");
		gtk_grid_attach(GTK_GRID(grid), marks_label, 2, i + 1, 1, 1);

		// Create a text entry field for the marks    
		student.mark_entry[i] = gtk_entry_new();
		gtk_grid_attach(GTK_GRID(grid), student.mark_entry[i], 3, i + 1, 1, 1);
	}
	// Add the grid to the box at the end (bottom) of the box
	gtk_box_pack_start(GTK_BOX(box), grid_x, TRUE, TRUE, 0);
	
	
	
	// Separator
    separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(box), separator, FALSE, FALSE, 0);


    // Label for Subjects Section
    GtkWidget *subjects_grid_title = gtk_label_new("Fill The Title and Marks for Each Subject \n Leave blank or add 0 for Deferred Units");
    gtk_grid_attach(GTK_GRID(grid_x), subjects_grid_title, 0, 0, 2, 1);


	// Process Btn
    GtkWidget *process_button = gtk_button_new_with_label("PROCESS");
	// Btn to quit the application
    GtkWidget *quit_button = gtk_button_new_with_label("Quit");

    //
	gtk_box_pack_start(GTK_BOX(box), process_button, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), quit_button, FALSE, FALSE, 0);


    // Store the entry widgets in the student struct
    student.name_entry = name_entry;
    student.id_entry = id_entry;
    student.course_entry = course_entry;
    student.no_of_units_entry = no_of_units_entry;

	Widgets *widgets = g_malloc(sizeof(Widgets)); // Allocate memory
	widgets->student = &student; // Set the student
	widgets->window = window; //Set the window

	// Connect the "Process" button to the save_button_clicked function
    g_signal_connect(process_button, "clicked", G_CALLBACK(save_button_clicked), widgets);

    // Connect the Quit button click event to the callback function
    g_signal_connect(quit_button, "clicked", G_CALLBACK(on_quit_button_clicked), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
