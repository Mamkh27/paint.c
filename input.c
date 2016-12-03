//
//  main.c
//  input and related functions for final
//
//  Created by Zhouxuanchen on 12/1/16.
//  Copyright © 2016 Zhouxuanchen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char** canvas;

void ReadInput (){
    char c;
    printf("Enter your command: ");
    scanf("%c", &c);
    
    if(c == 'q'){
        Quit();
    }
    else if(c == 'h'){
        Help();
    }
    else if(c == 'w'){
        Write();
    }
    else if(c == 'e'){
        Erase();
    }
    else if(c == 'r'){
        Resize();
    }
    else if(c == 'a'){
        Add();
    }
    else if(c == 'd'){
        Delete();
    }
    else if(c == 's'){
        Save();
    }
    else if(c == 'l'){
        Load();
    }
    else{
        ReadInput ();
    }
}

void Resize(int numRows, int numCols){ 
    int updatedRows; 
	int updatedCols; 
	
	scanf("%d %d", &updatedRows, &updatedCols);
	 numRows = updatedRows;
	 numCols = updatedCols; 
	
	makeCanvas(updatedRows, updatedCols); 
	return;


void Quit(){
    exit (0); 
}

void Help(){

	printf("Commands:\n");
	printf("Help: h\n");
	printf("Quit: q\n");
	printf("Draw line: w row_start col_start row_end col_end\n");
	printf("Resize: r num_rows num_cols\n");
	printf("Add row or column: a [r | c] pos\n");
	printf("Delete row or column: d [r | c] pos\n");
	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
}
}

void Write(){
    int row1, col1, row2, col2;
    scanf(" %d %d %d %d", &row1, &col1, &row2, &col2);
    if(row1-row2 == col1-col2){
        LeftSlash(row1, col1, row2, col2);
    }
    else if(row1-row2 == col2-col1){
        RightSlash(row1, col1, row2, col2);
    }
    else if(row1 == row2){
        HorizontalDash(row1, col1, row2, col2);
    }
    else if(col1 == col2){
        VerticalDash(row1, col1, row2, col2);
    }
    else{
        printf("not a straight line.\n");
    }
}

void LeftSlash(int row1, int col1, int row2, int col2){
    int c;
    if(row2 < row1){
        c = row1;
        row1 = row2;
        row2 = c;
        c = col1;
        col1 = col2;
        col2 = c;
    }
    while(row1 <= row2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '/'){
            canvas[row1][col1] = '/';
        }
        else{
            canvas[row1][col1] = '+';
        }
        row1++; col1++;
    }
}

void RightSlash(int row1, int col1, int row2, int col2){
    int c;
    if(row2 < row1){
        c = row1;
        row1 = row2;
        row2 = c;
        c = col1;
        col1 = col2;
        col2 = c;
    }
    while (row1 <= row2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '\\'){
            canvas[row1][col1] = '\\';
        }
        else{
            canvas[row1][col1] = '+';
        }
        row1++; col1--;
    }
}

void HorizontalDash(int row1, int col1, int row2, int col2){
    int c;
    if(col2 < col1){
        c = col1;
        col1 = col2;
        col2 = c;
    }
    while (col1 <= col2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '-'){
            canvas[row1][col1] = '-';
        }
        else{
            canvas[row1][col1] = '+';
        }
        col1++;
    }
}

void VerticalDash(int row1, int col1, int row2, int col2){
    int c;
    if(row2 < row1){
        c = row1;
        row1 = row2;
        row2 = c;
    }
    while (row1 <= row2){
        if(canvas[row1][col1] == '*'||canvas[row1][col1] == '|'){
            canvas[row1][col1] = '|';
        }
        else{
            canvas[row1][col1] = '+';
        }
        row1++;
    }
}

void Erase (){
    int row, col;
    scanf(" %d %d", &row, &col);
    canvas[row][col] = '*';
}

 





















