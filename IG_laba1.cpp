// IG_laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////Домашняя работа перевернуть треугольник
#include <GL/glew.h>
#include <iostream>

#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/freeglut_std.h>
#include <GL/freeglut_ucall.h>
#include <GL/glut.h>

GLuint VBO;
void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	/*glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 01");

	// регистрация обратных вызовов
	glutDisplayFunc(renderScene);
	glClearColor(0.5f, 0.0f, 0.0f, 0.5f);

	// Основной цикл GLUT
	glutMainLoop();

	return 1;*/
	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Tutorial 01");

	glutDisplayFunc(renderScene);
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	glm::vec3 Vertices[3];
	Vertices[0] = glm::vec3(1.0f, 1.0f, 0.0f);
	Vertices[1] = glm::vec3(-1.0f, 1.0f, 0.0f);
	Vertices[2] = glm::vec3(0.0f, -1.0f, 0.0f);

	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glutMainLoop();
	

    
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
