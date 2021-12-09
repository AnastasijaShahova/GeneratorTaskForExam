import React from "react";
import { Routes, Route, Navigate } from "react-router-dom";
import { ResultModal } from "./components/ResultModal";
import { ListQuestionsPage } from "./pages/ListQuestionsPage";
import {MainPage} from "./pages/MainPage";
import {QuestionsPage} from "./pages/QuestionsPage";
import { VariantsPage } from "./pages/VariantsPage";

export const useRoutes = () => {
    return (
        <Routes>
            <Route path="/" element={<MainPage />} exact />

            <Route path="/variants" element={<VariantsPage />} />

            <Route path="/variants/:id" element={<ListQuestionsPage />} />

            <Route path="/questions" element={<QuestionsPage />} exact />

            <Route path="/result" element={<ResultModal />} exact />

            <Route path="*" element={<Navigate to="/" />} />
        </Routes>
    );
};
