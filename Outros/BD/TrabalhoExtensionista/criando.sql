CREATE TABLE DEPARTAMENTO (
    DepartamentoID INT PRIMARY KEY,
    Nome VARCHAR(100),
    ChefeDepartamento VARCHAR(100)
);

CREATE TABLE CURSO (
    CursoID INT PRIMARY KEY,
    Nome VARCHAR(100),
    Duracao INT,
    DepartamentoID INT,
    FOREIGN KEY (DepartamentoID) REFERENCES DEPARTAMENTO(DepartamentoID)
);

CREATE TABLE DISCIPLINA (
    DisciplinaID INT PRIMARY KEY,
    Nome VARCHAR(100),
    Creditos INT,
    CursoID INT,
    FOREIGN KEY (CursoID) REFERENCES CURSO(CursoID)
);

CREATE TABLE PROFESSOR (
    ProfessorID INT PRIMARY KEY,
    Nome VARCHAR(100),
    Titulo VARCHAR(100)
);

CREATE TABLE ALUNO (
    AlunoID INT PRIMARY KEY,
    Nome VARCHAR(100),
    DataNascimento DATE,
    CursoID INT,
    FOREIGN KEY (CursoID) REFERENCES CURSO(CursoID)
);

CREATE TABLE MATRICULA (
    MatriculaID INT PRIMARY KEY,
    AlunoID INT,
    DisciplinaID INT,
    DataInscricao DATE,
    NotaFinal DECIMAL(4,2),
    FOREIGN KEY (AlunoID) REFERENCES ALUNO(AlunoID),
    FOREIGN KEY (DisciplinaID) REFERENCES DISCIPLINA(DisciplinaID)
);

CREATE TABLE MINISTRACAO (
    MinistracaoID INT PRIMARY KEY,
    ProfessorID INT,
    DisciplinaID INT,
    FOREIGN KEY (ProfessorID) REFERENCES PROFESSOR(ProfessorID),
    FOREIGN KEY (DisciplinaID) REFERENCES DISCIPLINA(DisciplinaID)
);
