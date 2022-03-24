# IG_laba1
Ответственны за создание и изменения свойств окна:
glutInit(&argc, argv);
glutInitWindowSize(1024, 768);
glutInitWindowPosition(100, 100);
glutCreateWindow("Tutorial 01");

Обработка отображения:
glutDisplayFunc(renderScene);

Работа с буфером:
glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

Цикл:
glutMainLoop();

Отрисовываемая сцена:
glClear(GL_COLOR_BUFFER_BIT);
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
glDrawArrays(GL_TRIANGLES, 0, 3);
glDisableVertexAttribArray(0);
glutSwapBuffers();
    

