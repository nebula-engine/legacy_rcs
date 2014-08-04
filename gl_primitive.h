void client_gl_basic_cube()
{
    glPushMatrix();
    glBegin(GL_QUADS);

    /* This is the top face*/
    glNormal3d(0, 1, 0);
    glVertex3f( 0.5f, 0.5f,  0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f,  0.5f);
    /* This is the left face*/
    glNormal3d(-1, 0, 0);
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    /* This is the bottom face*/
    glNormal3d(0, -1, 0);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    // This is the right face
    glNormal3d(1, 0, 0);
    glVertex3f(0.5f, -0.5f,  0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f,  0.5f, -0.5f);
    glVertex3f(0.5f,  0.5f,  0.5f);
    /* This is the front face*/
    glNormal3d(0, 0, -1);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    /* This is the back face*/
    glNormal3d(0, 0, 1);
    glVertex3f( 0.5f,  0.5f, 0.5f);
    glVertex3f(-0.5f,  0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    
    glEnd();
    glPopMatrix();
};

void client_gl_basic_plane_XY()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    
    glNormal3f(0, 0, 1);
    glVertex3f( 0.5f,  0.5f, 0.0f);
    glVertex3f( 0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f,  0.5f, 0.0f);
    
    glEnd();
    glPopMatrix();
};

void client_gl_basic_plane_XZ()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    
    glNormal3d(0, 1, 0);
    glVertex3f( 0.5f, 0.0f,  0.5f);
    glVertex3f( 0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f,  0.5f);
    
    glEnd();
    glPopMatrix();
};
