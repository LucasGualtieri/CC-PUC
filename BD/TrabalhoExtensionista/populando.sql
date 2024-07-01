-- Departamento
INSERT INTO DEPARTAMENTO (DepartamentoID, Nome, ChefeDepartamento)
VALUES (1, 'Departamento de Ciências da Computação', 'Dr. Carlos Silva'),
       (2, 'Departamento de Engenharia Elétrica', 'Dra. Ana Souza');

-- Curso
INSERT INTO CURSO (CursoID, Nome, Duracao, DepartamentoID)
VALUES (101, 'Ciência da Computação', 8, 1),
       (102, 'Engenharia Elétrica', 10, 2);

-- Disciplina
INSERT INTO DISCIPLINA (DisciplinaID, Nome, Creditos, CursoID)
VALUES (1001, 'Banco de Dados', 4, 101),
       (1002, 'Redes de Computadores', 4, 101),
       (1003, 'Sistemas Digitais', 4, 102);

-- Professor
INSERT INTO PROFESSOR (ProfessorID, Nome, Titulo)
VALUES (201, 'Prof. João Santos', 'Doutor'),
       (202, 'Prof. Maria Oliveira', 'Mestre');

-- Aluno
INSERT INTO ALUNO (AlunoID, Nome, DataNascimento, CursoID)
VALUES (10001, 'Pedro Souza', '1998-05-15', 101),
       (10002, 'Ana Silva', '1999-07-20', 102);

-- Matricula
INSERT INTO MATRICULA (MatriculaID, AlunoID, DisciplinaID, DataInscricao, NotaFinal)
VALUES (5001, 10001, 1001, '2023-02-10', 8.5),
       (5002, 10001, 1002, '2023-02-10', 7.8),
       (5003, 10002, 1003, '2023-02-12', 9.0);

-- Ministracao
INSERT INTO MINISTRACAO (MinistracaoID, ProfessorID, DisciplinaID)
VALUES (7001, 201, 1001),
       (7002, 202, 1002);